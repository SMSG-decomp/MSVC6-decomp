void __thiscall ovl_add_candidate_entry_fragment(void *res,byte *sym,int naming_class)

{
  byte *pbVar1;
  
  pbVar1 = sym;
  if ((*sym & 0x1f) == 0x1a) {
    pbVar1 = (byte *)**(int **)(sym + 0x14);
  }
  if ((pbVar1[0x35] & 0xe0) == 0) {
    ovl_add_candidate_entry(res,(c1_symbol *)sym,(c1_symbol *)naming_class);
  }
  return;
}

