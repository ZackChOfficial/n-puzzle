import React from 'react'
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
const Span = styled.span`
    width: 100%;
    float: left;
    height: 150px;
    display: flex;
    flex-direction: column;
    -webkit-box-align: center;
    align-items: center;
`
export default function Description() {
    return <Descr>
        N Puzzle is a sliding blocks game that takes place on a k * k grid with ((k * k) - 1) tiles each numbered from 1 to N.
    <br/>
    <br/>
    <br/>
    <Span style={{textAlign: "center"}}>
        <svg height="40" viewBox="0 0 73 73" width="40" style={{transform: "rotate(0deg)", margin: "0px 2px"}}>
            <rect x="1.5" y="1.5" width="70" height="70" rx="10.5" ry="10.5" fill="rgba(255, 255, 255, 0)"></rect>
            <path stroke="#6B7280" fill="#6B7280" d="M61 3a9 9 0 0 1 9 9v49a9 9 0 0 1-9 9H12a9 9 0 0 1-9-9V12a9 9 0 0 1 9-9h49m0-3H12A12 12 0 0 0 0 12v49a12 12 0 0 0 12 12h49a12 12 0 0 0 12-12V12A12 12 0 0 0 61 0z"></path>
            <path d="M17.75 45.75l17.32-16.44a3.11 3.11 0 0 1 4.3.06l15.88 15.88" fill="none" stroke="#6B7280" strokeMiterlimit="10" strokeWidth="3"></path>
            </svg>
            <span className="bottom-keys">
                <svg height="40" viewBox="0 0 73 73" width="40" style={{transform: "rotate(270deg)", margin: "0px 2px"}}><rect x="1.5" y="1.5" width="70" height="70" rx="10.5" ry="10.5" fill="rgba(255, 255, 255, 0)"></rect>
                    <path stroke="#6B7280" fill="#6B7280" d="M61 3a9 9 0 0 1 9 9v49a9 9 0 0 1-9 9H12a9 9 0 0 1-9-9V12a9 9 0 0 1 9-9h49m0-3H12A12 12 0 0 0 0 12v49a12 12 0 0 0 12 12h49a12 12 0 0 0 12-12V12A12 12 0 0 0 61 0z"></path>
                    <path d="M17.75 45.75l17.32-16.44a3.11 3.11 0 0 1 4.3.06l15.88 15.88" fill="none" stroke="#6B7280" strokeMiterlimit="10" strokeWidth="3"></path>
                </svg>
                <svg height="40" viewBox="0 0 73 73" width="40" style={{transform: "rotate(180deg)", margin: "0px 2px"}}>
                    <rect x="1.5" y="1.5" width="70" height="70" rx="10.5" ry="10.5" fill="rgba(255, 255, 255, 0)"></rect>
                    <path stroke="#6B7280" fill="#6B7280" d="M61 3a9 9 0 0 1 9 9v49a9 9 0 0 1-9 9H12a9 9 0 0 1-9-9V12a9 9 0 0 1 9-9h49m0-3H12A12 12 0 0 0 0 12v49a12 12 0 0 0 12 12h49a12 12 0 0 0 12-12V12A12 12 0 0 0 61 0z"></path>
                    <path d="M17.75 45.75l17.32-16.44a3.11 3.11 0 0 1 4.3.06l15.88 15.88" fill="none" stroke="#6B7280" strokeMiterlimit="10" strokeWidth="3"></path>
                </svg>
                <svg height="40" viewBox="0 0 73 73" width="40" style={{transform: "rotate(90deg)", margin: "0px 2px"}}><rect x="1.5" y="1.5" width="70" height="70" rx="10.5" ry="10.5" fill="rgba(255, 255, 255, 0)"></rect>
                    <path stroke="#6B7280" fill="#6B7280" d="M61 3a9 9 0 0 1 9 9v49a9 9 0 0 1-9 9H12a9 9 0 0 1-9-9V12a9 9 0 0 1 9-9h49m0-3H12A12 12 0 0 0 0 12v49a12 12 0 0 0 12 12h49a12 12 0 0 0 12-12V12A12 12 0 0 0 61 0z"></path>
                    <path d="M17.75 45.75l17.32-16.44a3.11 3.11 0 0 1 4.3.06l15.88 15.88" fill="none" stroke="#6B7280" strokeMiterlimit="10" strokeWidth="3"></path>
                </svg>
            </span>
    <br/>
    Move tiles in grid to order them in spiral form.
    </Span>
    </Descr>
}