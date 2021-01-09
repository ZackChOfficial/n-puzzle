import React, { useEffect, useState } from 'react'
import styled from 'styled-components'
import Cell from './cells'
import Move from '../controller/move'

const Container = styled.div`
    border: 2px solid #000;
    width: 600px;
    height: 600px;;
    float:left;
    flex-wrap:wrap;
    position:relative;
    justify-content:space-between;
    align-content:space-between;
    margin: 0 auto;
    border-radius: 5px
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
                    size: 100 / props.size
                });
            }
        }
        setContent(newContent);
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
                    size: 100 / props.size
                });
            }
        }
        setContent(newContent);
    }, [props.numbers])
    return <>
        
        <br /><br />
        <Container id="board">
            {
                content.map(cell => <Cell id={cell.id} key={cell.key} left={cell.left} top={cell.top} size={cell.size} number={cell.key} />)
            }
        </Container>
    </>
}