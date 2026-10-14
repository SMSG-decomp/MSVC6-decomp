int __cdecl debug_tag_reference_record(short *rec,c1_symbol *based_var)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = based_var->storage & 7;
  if ((bVar2 != 4) && (bVar2 != 5)) {
    rec[1] = (bVar2 != 3) + 0x1007;
    rec[4] = 0;
    rec[5] = 0;
    rec[6] = 0;
    *(c1_u32 *)(rec + 2) = based_var->type->debug_index;
    iVar1 = debug_identifier_length((byte *)(rec + 7),based_var->name->text);
    *rec = (short)(iVar1 + 0xe);
    return iVar1 + 0xe;
  }
  rec[1] = 0x1006;
  rec[2] = 0;
  rec[3] = 0;
  *(c1_u32 *)(rec + 4) = based_var->type->debug_index;
  iVar1 = debug_identifier_length((byte *)(rec + 6),based_var->name->text);
  *rec = (short)(iVar1 + 0xc);
  return iVar1 + 0xc;
}

