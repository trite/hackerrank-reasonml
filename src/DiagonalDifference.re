// https://www.hackerrank.com/challenges/diagonal-difference/problem

open Trelude;

let diag1: (int, array(array(int))) => int =
  (len, matrix) => {
    rangeArr(0, len) |> Js.Array.map(x => matrix[x][x]) |> sum;
  };

let diag2: (int, array(array(int))) => int =
  (len, matrix) => {
    rangeArr(0, len) |> Js.Array.map(x => matrix[len - x - 1][x]) |> sum;
  };

let diagonalDifference: (int, array(array(int))) => int =
  (len, matrix) => {
    let d1 = diag1(len, matrix);
    let d2 = diag2(len, matrix);
    abs(d1 - d2);
  };

let parse: array(string) => array(array(int)) =
  Js.Array.map(Js.String.split(" ") >> Js.Array.map(int_of_string));

Readline.question("", matrixSize => {
  let matrixSize = matrixSize |> int_of_string;

  Readline.questionLines(~count=matrixSize, ~isDone=true, arr =>
    arr |> parse |> diagonalDifference(matrixSize) |> string_of_int |> Js.log
  );
});
