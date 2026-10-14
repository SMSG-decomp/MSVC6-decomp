void __fastcall asm_print_data_symbol_directive(c2_fe_symbol *s)

{
  uint uVar1;
  c2_fe_symbol *sec;
  char *pcVar2;
  int iVar3;
  uint8_t *puVar4;
  int iVar5;
  uint uVar6;
  uint32_t size;
  uint32_t uVar7;
  
  if ((((s->flags31 & 4) != 0) && ((s->flags31 & 2) == 0)) && (s->cls == '\x01')) {
    uVar6 = s->storage;
    if (((uVar6 & 0x780) != 0x100) &&
       ((((uVar1 = uVar6 & 0x70, uVar1 == 0x20 || (uVar1 == 0x60)) || (uVar1 == 0x50)) &&
        ((s->attrs & 0x480) == 0)))) {
      sec = fe_symbol_lookup_id(s->section_id);
      g_asm_current_segment = asm_switch_segment(sec,0);
      if ((uVar6 & 0x10000) == 0) {
        size = s->size;
      }
      else {
        size = *(uint32_t *)((int)&(s->u3e).label_flags + 2);
      }
      pcVar2 = asm_size_keyword(size);
      if (pcVar2 == (char *)0x0) {
        size = 1;
      }
      iVar3 = (int)s->size / (int)size;
      uVar7 = (g_asm_current_segment->u3e).label_flags;
      if ((int)size < 5) {
        if (4 < (int)uVar7) {
          uVar7 = 4;
        }
      }
      else if (8 < (int)uVar7) {
        uVar7 = 8;
      }
      if (((uVar6 >> 4 & 7) == 2) && (uVar6 = uVar6 >> 7 & 0xf, uVar6 != 1)) {
        if (uVar6 == 3) {
          pcVar2 = asm_size_keyword(size);
          puVar4 = fe_symbol_external_name(s);
          asm_printf("COMM\t%s:%s",puVar4,pcVar2);
          if (1 < iVar3) {
            iVar3 = asm_printf(":0%lxH",iVar3);
            g_asm_column = g_asm_column + iVar3;
          }
          if ((s->name != (char *)0x0) && (*s->name == '?')) {
            asm_print_symbol_operand(s,1);
          }
          g_asm_column = 0;
          asm_printf(g_asm_newline);
          return;
        }
        if (uVar6 != 4) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\list.c",0x3d3);
        }
      }
      if ((uint)g_asm_current_segment->refcount % uVar7 != 0) {
        asm_printf("\tALIGN\t%d\n",uVar7);
        g_asm_column = 0;
        asm_printf(g_asm_newline);
        g_asm_current_segment->refcount =
             g_asm_current_segment->refcount + -1 + uVar7 & ~(uVar7 - 1);
      }
      puVar4 = fe_symbol_external_name(s);
      iVar5 = asm_printf("%s",puVar4);
      g_asm_column = g_asm_column + iVar5;
      asm_pad_to_column(8);
      pcVar2 = asm_data_directive_for_size(size);
      iVar5 = asm_printf("%s",pcVar2);
      g_asm_column = g_asm_column + iVar5;
      asm_pad_to_column(0x10);
      iVar5 = asm_printf("0%lxH DUP (?)",iVar3);
      g_asm_column = g_asm_column + iVar5;
      if ((s->name != (char *)0x0) && (*s->name == '?')) {
        asm_print_symbol_operand(s,1);
      }
      g_asm_column = 0;
      asm_printf(g_asm_newline);
      g_asm_current_segment->refcount = g_asm_current_segment->refcount + iVar3 * size;
    }
  }
  return;
}

