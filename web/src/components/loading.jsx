import React from 'react'
import styled from 'styled-components'
import Spinner from './spinner'

const Loader = styled.div`
    position: absolute;
    width: 100%;
    height: 100%;
    background-color: rgba(0,0,0,.45);
`

export default function Loading()
{
    return <Loader><Spinner /></Loader>
}