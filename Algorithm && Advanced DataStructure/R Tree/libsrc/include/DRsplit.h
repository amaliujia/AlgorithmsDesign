

extern int DRnodeSplit(
        int     rfd,
        int     childno,
        DRrect  *childcov,
        char    *pagebuf0,
        char    *pagebuf1);


extern void DRnodeSplitInit(
        int     rfd,
        DRrect  *childcov,
        char    *pagebuf);

extern void DRnodeSplitPickSeeds(
        int     rfd,
        DRrect  *childcov,
        char    *pagebuf);

extern void DRnodeSplitDistribute(
        int     rfd,
        DRrect  *childcov,
        char    *pagebuf);

extern void DRnodeSplitClassify(
        int     rfd,
        int     entry,
        int     group,
        DRrect  *childcov,
        char    *pagebuf);

extern void DRnodeSplitLoadNodes(
        int     rfd,
        int     childno,
        DRrect  *childcov,
        char    *pagebuf0,
        char    *pagebuf1);
