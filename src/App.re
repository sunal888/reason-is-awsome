type route =
  | Home
  | Profile;

let urlToRoute = (url: ReasonReactRouter.url) =>
  switch (url.hash) {
  | "profile" => Profile
  | _ => Home
  };

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let (route, setRoute) = React.useState(() => urlToRoute(url));

  let _ =
    React.useEffect1(
      () => {
        setRoute(_ => urlToRoute(url));
        None;
      },
      [|url.hash|],
    );

  <>
    <div>
      <a href="#home"> {React.string("Home")} </a>
      <a href="#profile"> {React.string("Profile")} </a>
    </div>
    {switch (route) {
     | Home => <Home />
     | Profile => <Profile />
     }}
  </>;
};
