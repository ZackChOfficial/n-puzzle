import React from 'react'
import styled from 'styled-components'


const Container = styled.div`
    background: #52b4ff;
    text-align: center;
    width:90px;
    height:90px;
    display: flex;
    align-items: center;
    justify-content:center;
    border-radius:8px;
    font-size:36px;
    font-family: 'Pacifico', cursive;
    position: relative;
    &:before{
        content:'';
        width:22px;
        height:22px;
        background:#bbb;
        border-radius:50%;
        position:absolute;
        top:15px;
        left:18px;
        z-index:0;
    }
    &:after{
        content:'';
        width:50px;
        height:50px;
        background:#bbb;
        border-radius:50%;
        position:absolute;
        top:30px;
        left:30px;
        z-index:0;
    }
`

const Number = styled.h1`
    color:white;
    text-shadow: 2px 2px 0 #000;
    z-index:99;
    transform:translateY(-10px)
`
export default function Cell(props) {
    return <Container><Number>{props.number}</Number></Container>
}