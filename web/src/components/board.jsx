import React from 'react'
import styled from 'styled-components'
import Cell from './cells'


const Container = styled.div`
border: 1px solid #444;
width: 400px;
height:400px;
display: flex;
flex-wrap:wrap;
justify-content:space-between;
align-content:space-between;
`
const Space = styled.div`

width:90px;
height:90px;
`
export default function(props)
{
    return <Container>
        <Cell number="1"/><Cell number="1"/><Cell number="1"/><Cell number="1"/>
        <Cell number="1"/><Cell number="1"/><Cell number="1"/><Cell number="1"/>
        <Cell number="1"/><Cell number="1"/><Space/><Cell number="1"/>
        <Cell number="1"/><Cell number="1"/><Cell number="1"/><Cell number="1"/>
    </Container>
}