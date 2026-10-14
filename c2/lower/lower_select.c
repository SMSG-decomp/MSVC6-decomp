c2_tuple * __fastcall lower_select(c2_tuple *t)

{
  c2_tuple *pcVar1;
  uint local_8;
  uint local_4;
  
  lower_select_sbb(t,0,&local_8);
  lower_select_setcc(t,0,&local_4);
  if (local_8 <= local_4) {
    pcVar1 = lower_select_sbb(t,1,&local_8);
    return pcVar1;
  }
  pcVar1 = lower_select_setcc(t,1,&local_4);
  return pcVar1;
}

