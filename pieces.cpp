#include <vector>
#include "pieces.hpp"

int pieces[7][4][5][5] = {
        //O piece
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                }
        },
        //J piece
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {1, 1, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 1, 1},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0}
                }

        },
        //L piece
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 1},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {1, 1, 2, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                }
        },
        //S piece
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0}
                },
        },
        //Z piece
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                }
        },
        //T piece
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                }
        },
        //I piece
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {1, 1, 2, 1, 1},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {1, 1, 2, 1, 1},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0}
                }
        }
};


struct Piece {
    auto getBlockType(int piece, int rotation, int y, int x) -> int{
        return pieces[piece][rotation][y][x];
    };
    auto getInitialPosition (int piece, int rotation) -> std::vector<int> {
        return {-2, -2};
    };
};