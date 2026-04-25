#pragma once

#include "CDominoes.h"
#include "CPlayer.h"
#include "CRandom.h"

#include <pthread.h>
#include <vector>

class CTable : public CRandom {
private:
    CPlayer* player1;
    CPlayer* player2;
    CDominoes* dominoes;

    std::vector<Domino> train;
    int head;
    int tail;
    int consecutivePasses;
    pthread_mutex_t tableMutex;

    struct TurnData {
        CTable* table;
        CPlayer* player;
        bool played;
    };

public:
    CTable(CPlayer* p1, CPlayer* p2, CDominoes* d);
    ~CTable();

    void API();

private:
    void create_dominoes();
    void draw_dominoes();
    int who_first();
    void first_piece(int& currentPlayer);
    void run_game(int currentPlayer);
    bool take_turn(CPlayer& p);
    void printTrain() const;
    void final_report();

    static void* playerThread(void* arg);
};
