(define ones (cons 1 (lambda () ones)))

(define (sum-streams s1 s2) 
           (cons (+ (car s1) (car s2)) 
                 (lambda () (sum-streams ((cdr s1)) 
                                         ((cdr s2))))))
((cdr (sum-streams ones ones)))

(define ints 
        (cons 0 (lambda () (sum-streams ints ones))))


(define-syntax cons-stream
  (syntax-rules ()
    [(_ h t) (cons h (lambda () t))]))

(define (head-stream s) (car s))
(define (tail-stream s) ((cdr s)))
(define (null-stream? s) (null? s))

(define (sum-streams s1 s2) 
           (cons-stream (+ (head-stream s1) (head-stream s2)) 
                        (sum-streams (tail-stream s1) 
                                     (tail-stream s2))))

(define ints (cons-stream 0 (sum-streams ints ones)))

(define (ref-stream s n)
  (if (= n 0)
      (head-stream s)
      (ref-stream (tail-stream s) (- n 1))))

;(define-syntax my-or
;  (syntax-rules ()
;    [(_) #f]
;    [(_ e) e]
;    [(_ e1 e2 ...) (let ((t e1)) (if t t (my-or e2 ...)))]))