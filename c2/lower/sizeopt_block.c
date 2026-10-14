void __fastcall sizeopt_block(c2_block *block)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = sizeopt_forward_scan(block);
    iVar2 = sizeopt_backward_scan(block);
    if (0x31 < iVar3) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\sizeopt.c",0x45);
    }
    iVar3 = iVar3 + 1;
  } while (iVar1 != 0 || iVar2 != 0);
  if (g_opt_favor_speed == 0) {
    sizeopt_narrow_to_word(block);
  }
  return;
}

