let str = ReasonReact.string;

[@bs.module] external logo: string = "../assets/logo.png";

module Styles = {
  open Css;
  let header =
    style([
      backgroundColor(rgba(238, 35, 45, 1.0)),
      display(flexBox),
      justifyContent(spaceBetween),
      alignItems(center),
    ]);
  let title = style([color(white), fontSize(px(36)), fontWeight(bold)]);
  let logo = style([width(px(50)), height(px(50)), marginLeft(px(32))]);
  let search_input_wrapper = style([marginRight(px(32))]);
  let search_input = style([marginRight(px(8))]);
};

[@react.component]
let make = () => {
  <div>
    <header className=Styles.header>
      <img className=Styles.logo src=logo />
      <span className=Styles.title> {str("Super Marvel Heroes")} </span>
      <div className=Styles.search_input_wrapper>
        <input className=Styles.search_input placeholder="search" />
        <button> {str("Search")} </button>
      </div>
    </header>
    <a href="./index.html"> {str("Home")} </a>
    <a href="#"> {str("Profile")} </a>
    <a href="#"> {str("Archetype")} </a>
    <a href="#"> {str("Competency")} </a>
  </div>;
};