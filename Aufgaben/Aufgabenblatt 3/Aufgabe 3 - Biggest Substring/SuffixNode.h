#ifndef AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXNODE_H
#define AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXNODE_H


class SuffixNode {
    public:
        int depth, begin, end;
        SuffixNode **children;
        SuffixNode *parent, *suffixLink;
        /*
         * Constructor
         */
        SuffixNode(int begin, int end, int depth, SuffixNode *parent);

        bool contains(int d);
};


#endif //AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXNODE_H
