import * as readline from 'readline';

function getNumberFromStdin(): Promise<number> {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  return new Promise<number>((resolve, reject) => {
    rl.question('Please enter a number: ', (answer) => {
      const num = parseInt(answer, 10);
      if (!isNaN(num)) {
        resolve(num);
      } else {
        reject(new Error("Invalid input. Please enter a valid number."));
      }
      rl.close();
    });
  });
}
function main() {

    getNumberFromStdin().then(input1 => 
          {getNumberFromStdin().then(input2 => 
              console.log(input1 + input2))});   

    console.log("(This will print before any input is processed.)");
}

main();