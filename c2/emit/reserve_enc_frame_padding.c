void __fastcall reserve_enc_frame_padding(c2_function *fn,int pad)

{
  if (pad < 0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\stack.c",0x111);
  }
  if ((fn->fsym->u3e).label_flags != 0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\stack.c",0x112);
  }
  (fn->fsym->u3e).label_flags = pad;
  g_frame_cursor = g_frame_cursor - pad;
  return;
}

