char * __cdecl decorate_name_body(char *out,c1_symbol *sym,c1_symbol *sym2)

{
  byte *pbVar1;
  char cVar2;
  c1_type *pcVar3;
  bool bVar4;
  int iVar5;
  byte bVar6;
  uint codes;
  byte *pbVar7;
  char *pcVar8;
  int iVar9;
  byte *pbVar10;
  
  iVar5 = g_decorate_outermost;
  g_decorate_outermost = 0;
  codes = decorate_symbol_codes(sym);
  iVar9 = g_decorate_error_name_counter;
  if ((g_error_count != 0) || (codes == 0)) {
    pcVar8 = sym->name->text;
    if ((codes != 0) && (g_error_count != 0)) {
      g_decorate_error_name_counter = g_decorate_error_name_counter + 1;
      iVar9 = format_snprintf(out," %s %d",-1,pcVar8,iVar9);
      g_decorate_outermost = iVar5;
      return out + iVar9;
    }
    if (iVar5 == 0) {
      *out = '?';
      pcVar8 = decorate_name_with_backreference(out + 1,(int)sym->name,0);
      *pcVar8 = '@';
      pcVar8[1] = '9';
      out = pcVar8 + 2;
    }
    else {
      cVar2 = *pcVar8;
      *out = cVar2;
      while (cVar2 != '\0') {
        pcVar8 = pcVar8 + 1;
        cVar2 = *pcVar8;
        out[1] = cVar2;
        out = out + 1;
      }
    }
    bVar6 = sym->kind & 0x1f;
    if (((((bVar6 == 7) || (bVar6 == 8)) || (bVar6 == 6)) &&
        ((pcVar3 = sym->type,
         (*(byte *)((-(uint)((pcVar3->code & 0x80) != 0) & (uint)pcVar3) + 2) & 7) == 5 ||
         ((*(byte *)(((uint)pcVar3 & -(uint)((pcVar3->code & 0x80) != 0)) + 2) & 7) == 3)))) &&
       (((sym->flags1 & 2) != 0 ||
        (((sym->name->flags & 0x40000000) != 0 && (sym->scope_index == 0)))))) {
      if ((sym->flags5 & 0x40) == 0) {
        func_check_argument_bytes((int)sym);
      }
      iVar9 = format_snprintf(out,"@%d",-1,(uint)(sym->tail).fn.unk2c);
      out = out + iVar9;
    }
    g_decorate_outermost = iVar5;
    return out;
  }
  if (sym2 == (c1_symbol *)0x0) {
    sym2 = sym;
  }
  *out = '?';
  pbVar7 = (byte *)(out + 1);
  if (((codes == 0x24) || (codes == 0x25)) || (codes == 0x26)) {
    pbVar10 = (byte *)(sym2->name->text + 1);
    if (codes != 0x24) {
      bVar6 = *pbVar10;
      bVar4 = false;
      do {
        if ((bVar6 == 0) || (bVar4)) {
          g_decorate_outermost = iVar5;
          return (char *)pbVar7;
        }
        if (bVar6 == 0x40) {
          if ((pbVar7[-1] != 0x40) || (pbVar10[1] == 0x40)) {
            *pbVar7 = 0x40;
            goto LAB_10474766;
          }
          *pbVar7 = 0x40;
          pbVar7[1] = 0x24;
          if (codes == 0x25) {
            pbVar7[2] = 0x44;
            pbVar7 = pbVar7 + 3;
            bVar4 = true;
          }
          else {
            pbVar7[2] = 0x45;
            pbVar7 = pbVar7 + 3;
            bVar4 = true;
          }
        }
        else {
          *pbVar7 = bVar6;
LAB_10474766:
          pbVar7 = pbVar7 + 1;
          bVar4 = false;
        }
        pbVar10 = pbVar10 + 1;
        bVar6 = *pbVar10;
      } while( true );
    }
    sym2->flags1 = sym2->flags1 & 0xfc;
    sym2->storage = sym2->storage & 0xf8 ^ 3;
    bVar6 = *pbVar10;
    while ((bVar6 != 0 && (bVar6 != 0x40))) {
      *pbVar7 = bVar6;
      pbVar1 = pbVar10 + 1;
      pbVar7 = pbVar7 + 1;
      pbVar10 = pbVar10 + 1;
      bVar6 = *pbVar1;
    }
    *pbVar7 = 0x40;
    pbVar7 = pbVar7 + 1;
  }
  else {
    pbVar7 = decorate_name_operator_or_name(pbVar7,sym,codes);
  }
  pcVar8 = decorate_scope_chain((char *)pbVar7,&sym2->kind);
  *pcVar8 = '@';
  if (codes == 0x24) {
    pbVar7 = decorate_storage_code((byte *)(pcVar8 + 1),sym2,sym,0x24);
    sym2->flags1 = sym2->flags1 & 0xfe | 2;
    sym2->storage = sym2->storage & 0xf8 ^ 1;
    g_decorate_outermost = iVar5;
    return (char *)pbVar7;
  }
  pbVar7 = decorate_storage_code((byte *)(pcVar8 + 1),sym,(c1_symbol *)0x0,codes);
  g_decorate_outermost = iVar5;
  return (char *)pbVar7;
}

