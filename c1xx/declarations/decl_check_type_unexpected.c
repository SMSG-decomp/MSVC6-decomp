void __fastcall decl_check_type_unexpected(int state)

{
  short sVar1;
  c1_u8 *pcVar2;
  byte bVar3;
  c1_type *pcVar4;
  c1_arena *a;
  c1_u8 *pcVar5;
  int iVar6;
  undefined4 unaff_ESI;
  uint code;
  uint *puVar7;
  uint *puVar8;
  
  pcVar4 = *(c1_type **)(state + 0x30);
  if (pcVar4 == (c1_type *)0x0) {
    if (*(short *)(state + 0x40) == 0) {
      sVar1 = *(short *)(state + 0x42);
      if (sVar1 == 0) {
        *(byte *)(state + 0x14) = *(byte *)(state + 0x14) | 0x10;
      }
      else if ((g_compile_flags_c4 & 0x10000000) != 0) {
        g_yylval._0_2_ = sVar1;
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar5 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          a = g_arenas + g_token_arena_index;
          pcVar5 = a->cur;
          pcVar2 = g_arenas[g_token_arena_index].end;
          a->cur = pcVar5 + 0x30;
          if (pcVar2 < pcVar5 + 0x30) {
            arena_grow(a);
          }
        }
        if (pcVar5 == (c1_u8 *)0x0) {
          pcVar5 = (c1_u8 *)0x0;
        }
        else {
          *pcVar5 = 0xa5;
          puVar7 = &g_yylval;
          puVar8 = (uint *)(pcVar5 + 8);
          for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        *(c1_u8 **)(state + 0xc) = pcVar5;
        if (*(char *)(state + 0x2c) == '\0') {
          return;
        }
        diag_error(0x3e,g_type_int);
        return;
      }
      if (sVar1 == 0) {
        *(c1_type **)(state + 4) = g_type_int;
        goto LAB_10407565;
      }
      *(undefined2 *)(state + 0x40) = 0x13;
    }
    else {
      *(byte *)(state + 0x28) = *(byte *)(state + 0x28) | 4;
    }
    pcVar4 = decl_basic_specifier_type(*(ushort *)(state + 0x40),*(c1_u16 *)(state + 0x42));
    *(c1_type **)(state + 4) = pcVar4;
  }
  else if (*(ushort *)(state + 0x42) == 0) {
    *(c1_type **)(state + 4) = pcVar4;
  }
  else {
    code = CONCAT22((short)((uint)unaff_ESI >> 0x10),pcVar4->code) & 0xffff0083;
    if ((short)code == 0x81) {
      diag_warning(1,0xb4);
      *(undefined2 *)(state + 0x42) = 0;
      decl_check_qualifier_position(*(c1_type **)(state + 0x30),(c1_decl_spec_scan *)state);
      return;
    }
    bVar3 = (byte)pcVar4->code;
    if (((char)bVar3 < '\0') && ((bVar3 & 0x8f) == 0x80)) {
      decl_check_type_unexpected_ignore_qualifiers((c1_decl_spec_scan *)state,code);
      return;
    }
    pcVar4 = type_with_added_qualifiers(pcVar4,*(ushort *)(state + 0x42));
    *(c1_type **)(state + 4) = pcVar4;
  }
LAB_10407565:
  if ((*(ushort *)(state + 0x42) & 0x300) != 0) {
    diag_error(0xdb);
  }
  return;
}

