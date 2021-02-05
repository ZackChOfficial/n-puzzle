export const  algorithms = [
    { value: 'A_STAR', label: 'A Star' },
    { value: 'IDA_STAR', label: 'Ida Star' },
]

export const sizes = [
    { value: 0, label: '3x3' },
    { value: 1, label: '4x4' },
  ]

export const heuristics = [
    { value: 'MANHATTAN_DISTANCE', label: 'Manhattan distance' },
    { value: 'MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT', label: 'Linear conflict' },
    { value: 'DISJOINT_PATTERN_DATABASE', label: 'Pattern databases 5-5-5' },
]


export const solutionSize4 = [1,2,3,4,12,13,14,5,11,0,15,6,10,9,8,7]
export const solutionSize3 = [1,2,3,8,0,4,7,6,5]

export const speed = 0.2