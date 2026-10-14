void il_emitter_browse_pch_name(char *name)

{
  int iVar1;
  uint *src;
  uint *puVar2;
  uint rec [6];
  
  src = g_browse_record_zero;
  puVar2 = rec;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *src;
    src = src + 1;
    puVar2 = puVar2 + 1;
  }
  browse_flush_queue();
  rec[0]._0_1_ = 0xf;
  rec[0]._1_1_ = rec[0]._1_1_ | 2;
  rec[3] = (uint)mem_xstrdup(name);
  browse_record_type((c1xx_browse_record *)rec);
  return;
}

