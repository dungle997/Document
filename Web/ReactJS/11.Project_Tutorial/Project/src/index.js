import React from 'react';
import ReactDOM from 'react-dom'
import App from './App';
// import store from './redux/store'
// import {Provider} from 'react-redux' 
import GlobalStyles from './components/GlobalStyles'

ReactDOM.render(

  // <Provider store = {store}>
      <GlobalStyles>
        <App />
      </GlobalStyles>
  // </Provider>
  , 
  document.getElementById('root')
);



