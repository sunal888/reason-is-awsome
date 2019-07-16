let str = ReasonReact.string;

[@react.component]
let make = () => {
  <div> <h2> {str("PROFILE")} </h2> </div>;
};