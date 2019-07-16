/* type page =
  | Home
  | Profile;

module type Mapper = {
  let toPage: ReasonReact.Router.url => page;
  let toUrl: page => string;
};

module Mapper: Mapper = {
  let toPage = (url: ReasonReact.Router.url) =>
    switch (url.hash) {
    | "profile" => Profile
    | _ => Home
    };
  let toUrl = page =>
    switch (page) {
    | Profile => "profile"
    | _ => "home"
    };
};

let str = ReasonReact.string;

module App = {
  type state = {route: page};
  type action =
    | UpdatePage(page);
  let component = ReasonReact.reducerComponent("App");

  let make = _children => {
    ...component,
    initialState: () => {route: Home},
    reducer: (action, _state) =>
      switch (action) {
      | UpdatePage(route) => ReasonReact.Update({route: route})
      },
    didMount: self => {
      let watcherID =
        ReasonReact.Router.watchUrl(url =>
          switch (route) {
          | Home => <Home />
          | Profile => <Profile />
          }
        );
      ();
    },
    render: () =>
      <div>
        <a href="#home"> {str("Home")} </a>
        <a href="#profile"> {str("Profile")} </a>
      </div>,
  };
}; */
