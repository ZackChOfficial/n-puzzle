import React, {useEffect, useState} from 'react'
import styled from 'styled-components'
import Cell from './cells'
import Move from '../controller/move'

const Container = styled.div`
    border: 1px solid #000;
    width: 400px;
    height:400px;
    display: flex;
    flex-wrap:wrap;
    position:relative;
    justify-content:space-between;
    align-content:space-between;
`

export default function(props)
{
    const [content, setContent] = useState([]);
    const [numbers, setNumbers] = useState([3,1,2,0,4,5,6,7,8,9,10,11,12,13,14,15]);
    const handleClick = (direction) => {
        const newState = Move(numbers, direction);
        setNumbers(newState);
        const size = parseInt(Math.sqrt(numbers.length));
        for (let i = 0; i < size; i++)
        {
            for (let j = 0; j < size; j++)
            {
                console.log(document.getElementById(numbers[i*size + j].toString()))
                const elem = document.getElementById(numbers[i*size + j].toString())
                elem.style.left =  j*(100/size);
                elem.style.left =  i*(100/size);
            }
        }
    }
    useEffect(() => {
        const content = [];
        const size = parseInt( Math.sqrt(numbers.length));
        for (let i = 0; i < size; i++)
        {
            for (let j = 0; j < size; j++)
            {
                if (numbers[i*size + j] == 0)
                continue;
                console.log("ID: ", numbers[i*size + j].toString())
                content.push(<Cell id={numbers[i*size + j].toString()} number={numbers[i*size + j]} key={numbers[i*size + j]} top={i*(100/size)} left={j*(100/size)} size={100/size}/>);
            }
        }
        setContent(content);
    },[])
    return <>
        <button onClick={() => handleClick("U")}>up</button>
            <button onClick={() => handleClick("R")}>right</button>
            <button onClick={() => handleClick("L")}>left</button>
            <button onClick={() => handleClick("D")}>down</button>
    <Container id="board">   
        {
           content
        }
    </Container>
    </>
}