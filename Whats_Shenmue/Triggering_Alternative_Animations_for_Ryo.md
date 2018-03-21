# Triggering Alternative Animations for Ryo

Various action animations for Ryo can be triggered in *What's Shenmue* by changing the offsets inside `MOTION.BIN` that are associated when the A button is pressed (which normally causes Ryo to crouch).

Normally, the crouch action consists of the following three animations:
1. AKI_AKI_SIT_TATEHIZA_ST = animation of Ryo kneeling down (triggered on pressing the A button)
2. AKI_AKI_SIT_TATEHIZA_LP = animation of Ryo posing in the kneeling position
3. AKI_AKI_SIT_TATEHIZA_EN = animation of Ryo standing up (triggered on pressing the A button again)

By editing the file (or alternatively editing memory directly using a Cheat Engine) in the area that contains the Motion Data Look-up Table and replacing the offset data associated with the above three motions with new offsets, Ryo can be made to perform any other set of actions that exist in the same file. Note: offsets for the actions named DMY_EMPTY0, DMY_EMPTY1, DMY_EMPTY2 can be substituted if no animation is wanted.
