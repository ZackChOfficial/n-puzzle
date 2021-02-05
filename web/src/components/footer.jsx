import React from 'react'
import styled from 'styled-components'

const Footer = styled.div`
margin: 60px 0;
`

const Heart = styled.span`
    color: red;
`

const Link = styled.a`
text-decoration: none;
color: #165896;
`

export default function () {
    return <Footer>Made with <Heart>❤</Heart> by<br/> <Link href="https://github.com/ZackChOfficial">Zakaria</Link> & <Link href="https://github.com/ayoubyt">Ayoub</Link></Footer>
}