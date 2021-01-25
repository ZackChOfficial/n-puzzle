import React from 'react'
import styled, { keyframes } from 'styled-components'


const textAnimation = keyframes`
    0% {
        background:  linear-gradient(90deg, rgba(63,94,251,1) 0%, rgba(252,70,107,1) 100%);
        background-clip: text;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        -moz-background-clip: text;
        -moz-text-fill-color: transparent;
        -o-background-clip: text;
        -o-text-fill-color: transparent;
    }
    10% {
        background:  linear-gradient(100deg, rgba(63,94,251,1) 0%, rgba(252,70,107,1) 100%);
        background-clip: text;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        -moz-background-clip: text;
        -moz-text-fill-color: transparent;
        -o-background-clip: text;
        -o-text-fill-color: transparent;
    }
    18% {
        background:  linear-gradient(110deg, rgba(63,94,251,1) 0%, rgba(252,70,107,1) 100%);
        background-clip: text;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        -moz-background-clip: text;
        -moz-text-fill-color: transparent;
        -o-background-clip: text;
        -o-text-fill-color: transparent;
    }
    25% {
        background:  linear-gradient(120deg, rgba(63,94,251,1) 0%, rgba(252,70,107,1) 100%);
        background-clip: text;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        -moz-background-clip: text;
        -moz-text-fill-color: transparent;
        -o-background-clip: text;
        -o-text-fill-color: transparent;
    }
    35% {
        background:  linear-gradient(140deg, rgba(63,94,251,1) 0%, rgba(252,70,107,1) 100%);
        background-clip: text;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        -moz-background-clip: text;
        -moz-text-fill-color: transparent;
        -o-background-clip: text;
        -o-text-fill-color: transparent;
    }
    50% {
        background:  linear-gradient(150deg, rgba(252,70,107,1) 0%,  rgba(63,94,251,1) 100%);
        background-clip: text;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        -moz-background-clip: text;
        -moz-text-fill-color: transparent;
        -o-background-clip: text;
        -o-text-fill-color: transparent;
    }
    70% {
        background:  linear-gradient(165deg, rgba(252,70,107,1) 0%,  rgba(63,94,251,1) 100%);
        background-clip: text;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        -moz-background-clip: text;
        -moz-text-fill-color: transparent;
        -o-background-clip: text;
        -o-text-fill-color: transparent;
    }
    100% {
        background:  linear-gradient(180deg, rgba(252,70,107,1) 0%,  rgba(63,94,251,1) 100%);
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
 }
`

export default function () {
    return <Header><h1>N-puzzle</h1></Header>
}