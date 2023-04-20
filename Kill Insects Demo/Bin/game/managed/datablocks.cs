$managedDatablockSet = new SimSet() {
   canSaveDynamicFields = "1";
      setType = "Datablocks";

   new t2dImageMapDatablock(L3_BackGroundImageMap) {
      imageName = "~/data/images/L3_BackGround.dds";
      imageMode = "CELL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "0";
      preferPerf = "1";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "1";
      cellCountY = "1";
      cellWidth = "748";
      cellHeight = "512";
      preload = "1";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dImageMapDatablock(L3_PaiziImageMap) {
      imageName = "~/data/images/L3_Paizi.dds";
      imageMode = "FULL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "0";
      preferPerf = "1";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "-1";
      cellCountY = "-1";
      cellWidth = "0";
      cellHeight = "0";
      preload = "1";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dImageMapDatablock(L3_FeiChongImageMap) {
      imageName = "~/data/images/L3_FeiChong.dds";
      imageMode = "CELL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "1";
      preferPerf = "1";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "7";
      cellCountY = "3";
      cellWidth = "66";
      cellHeight = "58";
      preload = "1";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dImageMapDatablock(BeginImageMap) {
      imageName = "~/data/images/Begin.dds";
      imageMode = "FULL";
      frameCount = "-1";
      filterMode = "SMOOTH";
      filterPad = "0";
      preferPerf = "1";
      cellRowOrder = "1";
      cellOffsetX = "0";
      cellOffsetY = "0";
      cellStrideX = "0";
      cellStrideY = "0";
      cellCountX = "-1";
      cellCountY = "-1";
      cellWidth = "0";
      cellHeight = "0";
      preload = "1";
      allowUnload = "0";
      force16Bit = "0";
   };
   new t2dAnimationDatablock(L3_FeiChongAnimation) {
      imageMap = "L3_FeiChongImageMap";
      animationFrames = "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17";
      animationTime = "0.6";
      animationCycle = "1";
      randomStart = "0";
      startFrame = "0";
      animationPingPong = "0";
      animationReverse = "0";
   };
};