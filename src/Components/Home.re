let str = ReasonReact.string;

[@react.component]
let make = () => {
  <div> <h2> {str("HOME")} </h2> </div>;
};