import React, {useEffect} from 'react'
import styled from 'styled-components'


const Container = styled.div`
    background: #52b4ff;
    text-align: center;
    width:calc(${props => props.size}% - 10px);
    height:calc(${props => props.size}% - 10px);
    display: flex;
    align-items: center;
    justify-content:center;
    border-radius:8px;
    font-size:36px;
    font-family: 'Pacifico', cursive;
    position: absolute;
    margin:4px;
    top: ${props => props.top}%;
    left: ${props => props.left}%;
`

const Number = styled.h1`
    color:white;
    text-shadow: 2px 2px 0 #000;
    z-index:99;
    transform:translateY(-10px);
    position:relative;
    z-index:0;
`
export default function Cell(props) {
    return <Container top={props.top} left={props.left} size={props.size} id={props.id}><Number>{props.number}</Number></Container>
}