import React, {useEffect} from 'react'
import styled from 'styled-components'


const Container = styled.div`
    background: ${props => props.rightPlace ? "#9fc9be": "#d0d4e0"};
    text-align: center;
    width:calc(${props => props.size}% - 10px);
    height:calc(${props => props.size}% - 10px);
    display: flex;
    align-items: center;
    justify-content:center;
    border-radius:4px;
    font-size:36px;
    font-family: 'Pacifico', cursive; 
    position: absolute;
    margin:4px;
    top: ${props => props.top}%;
    left: ${props => props.left}%;
    transition: all .2s ease-in-out;
    border:1px solid ${props => props.rightPlace ? "#298e73": "#808caf"};
    color:${props => props.rightPlace ? "#298e73": "#808caf"};
    text-shadow: 2px 2px 0 ${props => props.rightPlace ? "#186651": "#397284"};
`

const Number = styled.h1`
    transform:translateY(-10px);
    z-index:99;
    position:relative;
    z-index:0;
`
export default function Cell(props) {
    return <Container top={props.top} left={props.left} size={props.size} id={props.id} rightPlace={props.rightPlace}><Number>{props.number}</Number></Container>
}