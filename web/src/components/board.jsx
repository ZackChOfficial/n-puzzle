import React, { useEffect, useState } from 'react'
import styled from 'styled-components'
import Cell from './cells'
import Loading from './loading'

const Container = styled.div`
    border: 2px solid #808caf;
    width: 550px;
    height: 550px;
    position:relative;
    margin: 0px auto;
    border-radius: 5px;
    @media (max-width: 1220px) {
        width: 400px;
        height: 400px;
    }
`

export default function (props) {
    const [content, setContent] = useState([]);

    useEffect(() => {
        const newContent = [];
        for (let i = 0; i < props.size; i++) {
            for (let j = 0; j < props.size; j++) {
                if (props.numbers[i * props.size + j] == 0)
                    continue;
                newContent.push({
                    key: props.numbers[i * props.size + j],
                    top: i * (100 / props.size),
                    left: j * (100 / props.size),
                    size: 100 / props.size,
                    rightPlace: props.numbers[i * props.size + j] == props.solution[i * props.size + j] 
                });
            }
        }
        setContent([newContent]);
    }, [props.size])
    useEffect(() => {
        const newContent = []
        for (let i = 0; i < props.size; i++) {
            for (let j = 0; j < props.size; j++) {
                if (props.numbers[i * props.size + j] == 0)
                    continue;
                newContent.push({
                    key: props.numbers[i * props.size + j],
                    top: i * (100 / props.size),
                    left: j * (100 / props.size),
                    size: 100 / props.size,
                    rightPlace: props.numbers[i * props.size + j] == props.solution[i * props.size + j] 
                });
            }
        }
        setContent(newContent);
    }, [props.numbers])

    return <Container id="board">
        {
            content.map(cell => <Cell id={cell.key} key={cell.key} left={cell.left} top={cell.top} size={cell.size} number={cell.key}  rightPlace={cell.rightPlace}/>)
        }
        {props.loading ? <Loading/> : ""}
    </Container>
}