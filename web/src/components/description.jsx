import React from 'react'
import Styled from 'styled-components'
import styled from 'styled-components'


const Descr = styled.div`
    position: -webkit-sticky;
    position: sticky;
    float:left;
    top: 0;
    left:0;
    padding-left: 5%;
    padding-top:180px;
    font-family: 'Lato', sans-serif;
    font-weight: 600;
    font-size: 18px;
    color: #6B7280;
    width: calc((100% - 600px)/2);
    @media only screen and (min-width: 1220px){
        width: calc((100% - 800px)/2.2);
    }
    @media only screen and (max-width: 768px){
        display: none;
    }
`

export default function Description() 
{
    return <Descr>N Puzzle is a sliding blocks game that takes place on a k * k grid with ((k * k) - 1) tiles each numbered from 1 to N. <br/> Your task is to reposition the tiles to their proper order.<br/> Note: First run will be a bit slower that usual.</Descr>
}