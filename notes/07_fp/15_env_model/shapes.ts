type Shape = {
    area: () => number;
    perimeter: () => number;
};

function createCircle(r: number): Shape {
    return {
        radius: r,
        area: () => Math.PI * r * r,
        perimeter: () => 2 * Math.PI * r
    } as Shape;
}

function createSquare(a: number): Shape {
    return {
        side: a, 
        area: () => a * a,
        perimeter: () => 4 * a
    } as Shape;
}

const circle : Shape = createCircle(1);
const square : Shape = createSquare(1);

console.log(circle.area()); 
console.log(square.area()); 