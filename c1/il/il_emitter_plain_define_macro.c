void __thiscall il_emitter_plain_define_macro(c1_il_emitter *this,int *macro)

{
  if (g_emitter_region_mode == 3) {
    *(uint *)(*macro + 8) = *(uint *)(*macro + 8) | 0x200000;
  }
  return;
}

