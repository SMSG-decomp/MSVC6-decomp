void __fastcall enc_finish_frame_padding(c2_pdb_func_syms *fs,c2_function *fn)

{
  uint uVar1;
  int iVar2;
  uint prev_frame_size;
  uint32_t frame_info_4;
  uint32_t frame_info_3;
  
  compute_frame_size(fn);
  iVar2 = FSGetFrameInfo(fs,&prev_frame_size,&frame_info_3,&frame_info_4);
  if (iVar2 == 0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\stack.c",0x25c);
  }
  uVar1 = fn->fsym->frame_size;
  if (prev_frame_size < uVar1) {
    reserve_enc_frame_padding(fn,0x40);
    return;
  }
  reserve_enc_frame_padding(fn,prev_frame_size - uVar1);
  return;
}

