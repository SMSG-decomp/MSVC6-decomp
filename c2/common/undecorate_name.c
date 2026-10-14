char * __fastcall undecorate_name(char *decorated,int full)

{
  __unDName(g_il_name_buffer,decorated,0x81e,undname_alloc,empty_hook,
            (-(uint)(full != 0) & 0xfffff080) + 0x1000 | 0x800);
  return g_il_name_buffer;
}

