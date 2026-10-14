int __cdecl pch_record_macro_definition(byte *name,byte *body,short key)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  c1_u8 *s;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  byte *pbVar7;
  bool bVar8;
  
  if (g_pch_directive_mode != 1) {
    piVar6 = g_pch_record_cursor;
    if (g_pch_directive_mode != 2) {
      return 0;
    }
    do {
      if (*piVar6 != 0) {
        if (*piVar6 != 1) {
          s = str_dup_arena(g_last_name->text,5);
          iVar3 = pch_auto_match_end();
          if (iVar3 == 3) {
            name_intern((char *)s);
          }
          return iVar3;
        }
        if ((short)piVar6[2] == key) {
          pbVar2 = (byte *)(piVar6 + 3);
          pbVar7 = name;
          do {
            bVar1 = *pbVar2;
            bVar8 = bVar1 < *pbVar7;
            if (bVar1 != *pbVar7) {
LAB_10485f9a:
              iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
              goto LAB_10485f56;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar2[1];
            bVar8 = bVar1 < pbVar7[1];
            if (bVar1 != pbVar7[1]) goto LAB_10485f9a;
            pbVar2 = pbVar2 + 2;
            pbVar7 = pbVar7 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
LAB_10485f56:
          if (iVar3 == 0) {
            uVar4 = 0xffffffff;
            pbVar2 = (byte *)(piVar6 + 3);
            do {
              if (uVar4 == 0) break;
              uVar4 = uVar4 - 1;
              bVar1 = *pbVar2;
              pbVar2 = pbVar2 + 1;
            } while (bVar1 != 0);
            pbVar2 = (byte *)(~uVar4 + 0xc + (int)piVar6);
            pbVar7 = body;
            do {
              bVar1 = *pbVar2;
              bVar8 = bVar1 < *pbVar7;
              if (bVar1 != *pbVar7) {
LAB_10485fa1:
                iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                goto LAB_10485f8a;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar2[1];
              bVar8 = bVar1 < pbVar7[1];
              if (bVar1 != pbVar7[1]) goto LAB_10485fa1;
              pbVar2 = pbVar2 + 2;
              pbVar7 = pbVar7 + 2;
            } while (bVar1 != 0);
            iVar3 = 0;
LAB_10485f8a:
            if (iVar3 == 0) {
              *piVar6 = 0;
              if (*g_pch_record_cursor != 0) {
                return 2;
              }
              do {
                g_pch_record_cursor =
                     (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
              } while (*g_pch_record_cursor == 0);
              return 2;
            }
          }
        }
      }
      piVar6 = (int *)(piVar6[1] + 0xc + (int)piVar6);
    } while( true );
  }
  uVar4 = 0xffffffff;
  pbVar2 = name;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar1 = *pbVar2;
    pbVar2 = pbVar2 + 1;
  } while (bVar1 != 0);
  uVar5 = 0xffffffff;
  pbVar2 = body;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    bVar1 = *pbVar2;
    pbVar2 = pbVar2 + 1;
  } while (bVar1 != 0);
  init_write_reloc_record(1,(uint)(ushort)key,(~uVar4 & 0xffff) + (~uVar5 & 0xffff));
  buffer_chain_append_bytes(name,~uVar4 & 0xffff,1,g_pch_record_list);
  buffer_chain_append_bytes(body,~uVar5 & 0xffff,1,g_pch_record_list);
  return 2;
}

