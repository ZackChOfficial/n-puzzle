import React from 'react'
import styled, { keyframes } from 'styled-components'


const textAnimation = keyframes`
     0%{
         background-position:0% 50%;
        background-clip: text;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        -moz-background-clip: text;
        -moz-text-fill-color: transparent;
        -o-background-clip: text;
        -o-text-fill-color: transparent;
        }
    50%{
        background-position:100% 50%;
        background-clip: text;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        -moz-background-clip: text;
        -moz-text-fill-color: transparent;
        -o-background-clip: text;
        -o-text-fill-color: transparent;
        }
    100%{
        background-position:0% 50%;
        background-clip: text;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        -moz-background-clip: text;
        -moz-text-fill-color: transparent;
        -o-background-clip: text;
        -o-text-fill-color: transparent;
        }
`
const Header = styled.div`
 h1 {
    font-family: 'Pacifico', cursive; 
    font-size:70px;
    margin: 10px 0;
    font-weight: bold;
    padding: 10px;
    animation: ${textAnimation} .6s linear  infinite alternate both;
    background: linear-gradient(42deg, #1abc9c, #8e44ad, #2980b9, #34495e, #ea4c88, #16a085, #8e44ad, #f1c40f, #29c5ff, #e74c3c);
    background-size: 2000% 2000%;
    -webkit-animation: ${textAnimation} 12s ease infinite;
    -moz-animation: ${textAnimation} 12s ease infinite;
    -o-animation: ${textAnimation} 12s ease infinite;
    animation: ${textAnimation} 12s ease infinite; 
    -webkit-text-fill-color: transparent;
    -moz-text-fill-color: transparent;
    -o-text-fill-color: transparent;
 }
`

export default function () {
    return <Header><h1>N-puzzle</h1></Header>
}