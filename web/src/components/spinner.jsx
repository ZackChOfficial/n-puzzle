import React from 'react'

export default function Spinner()
{
    return   <svg style={{position: "absolute", top: "49%", left:"52%", transform: "translate(-50%, -50%)", width: "90px", height:"90px" }}  xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100" preserveAspectRatio="xMidYMid" className="lds-pacman">
        <g ng-attr-style="display:{{config.showBean}}" style={{display:"block"}}>
          <circle cx="66.05" cy="50" r="4" ng-attr-fill="{{config.c2}}" fill="#abbd81">
            <animate attributeName="cx" calcMode="linear" values="95;35" keyTimes="0;1" dur="0.8" begin="-0.536s" repeatCount="indefinite"></animate>
            <animate attributeName="fill-opacity" calcMode="linear" values="0;1;1" keyTimes="0;0.2;1" dur="0.8" begin="-0.536s" repeatCount="indefinite"></animate>
          </circle>
          <circle cx="86.45" cy="50" r="4" ng-attr-fill="{{config.c2}}" fill="#abbd81">
            <animate attributeName="cx" calcMode="linear" values="95;35" keyTimes="0;1" dur="0.8" begin="-0.264s" repeatCount="indefinite"></animate>
            <animate attributeName="fill-opacity" calcMode="linear" values="0;1;1" keyTimes="0;0.2;1" dur="0.8" begin="-0.264s" repeatCount="indefinite"></animate>
          </circle>
          <circle cx="46.25" cy="50" r="4" ng-attr-fill="{{config.c2}}" fill="#abbd81">
            <animate attributeName="cx" calcMode="linear" values="95;35" keyTimes="0;1" dur="0.8" begin="0s" repeatCount="indefinite"></animate>
            <animate attributeName="fill-opacity" calcMode="linear" values="0;1;1" keyTimes="0;0.2;1" dur="0.8" begin="0s" repeatCount="indefinite"></animate>
          </circle>
        </g>
        <g ng-attr-transform="translate({{config.showBeanOffset}} 0)" transform="translate(-15 0)">
          <path d="M50 50L20 50A30 30 0 0 0 80 50Z" ng-attr-fill="{{config.c1}}" fill="#f8b26a" transform="rotate(16.875 50 50)">
            <animateTransform attributeName="transform" type="rotate" calcMode="linear" values="0 50 50;45 50 50;0 50 50" keyTimes="0;0.5;1" dur="0.8s" begin="0s" repeatCount="indefinite"></animateTransform>
          </path>
          <path d="M50 50L20 50A30 30 0 0 1 80 50Z" ng-attr-fill="{{config.c1}}" fill="#f8b26a" transform="rotate(-16.875 50 50)">
            <animateTransform attributeName="transform" type="rotate" calcMode="linear" values="0 50 50;-45 50 50;0 50 50" keyTimes="0;0.5;1" dur="0.8s" begin="0s" repeatCount="indefinite"></animateTransform>
          </path>
        </g>
      </svg>
}