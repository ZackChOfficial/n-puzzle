// import Wasm from 'react-wasm'


// const NPuzzle = () => {
//     <Wasm url="/add.wasm">
//     {({ loading, error, data }) => {
//       if (loading) return "Loading...";
//       if (error) return "An error has occurred";
 
//       const { module, instance } = data;
//       return <div>1 + 2 = {instance.exports.add(1, 2)}</div>;
//     }}
//   </Wasm>
// }