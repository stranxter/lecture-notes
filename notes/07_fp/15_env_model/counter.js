function counter(init) {

  let count = init;

  return {
    inc: step => count+=step,
    get: ()=>count
  };
}

const i1 = counter(0), i2 = counter(100);

i1.inc(1);i1.inc(1);i1.inc(1);i1.inc(1);
console.log(i1.get());

i2.inc(5);i2.inc(5);i2.inc(5);
console.log(i2.get());