char * __cdecl debug_symbol_name(c1_symbol *sym,char qualified)

{
  char cVar1;
  byte bVar2;
  c1_u8 cVar3;
  c1_symbol *sym_00;
  c1_type *type;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  size_t _Count;
  
  if ((sym->flags1 & 4) == 0) {
    return sym->name->text;
  }
  if (qualified == '\0') {
    g_debug_symbol_name_buffer[0] = '\0';
  }
  else {
    iVar5 = format_buffer_acquire();
    format_buffer_free(iVar5);
    sym_00 = g_scope_vector->entries[(short)sym->scope_index];
    iVar5 = format_buffer_alloc();
    format_qualified_name(iVar5,&sym_00->kind);
    _Count = 0x101;
    pcVar4 = format_buffer_text(iVar5);
    strncpy(g_debug_symbol_name_buffer,pcVar4 + 2,_Count);
    uVar7 = 0xffffffff;
    pcVar4 = g_debug_symbol_name_buffer;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    strncpy((char *)(~uVar7 + 0x104dc413),"::",0x101 - (~uVar7 - 1));
    g_debug_symbol_name_buffer[0x100] = '\0';
    format_buffer_leave();
  }
  if ((sym->tail).fn.op_token == '\x01') {
    bVar2 = sym->flags1;
    if (((bVar2 & 0x10) == 0x10) || ((bVar2 & 0x20) == 0x20)) {
      if ((bVar2 & 0x20) == 0x20) {
        uVar7 = 0xffffffff;
        pcVar4 = g_debug_symbol_name_buffer;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        strncpy((char *)(~uVar7 + 0x104dc413),"~",0x101 - (~uVar7 - 1));
        g_debug_symbol_name_buffer[0x100] = '\0';
      }
      pcVar4 = g_scope_vector->entries[(short)sym->scope_index]->name->text;
      if (*pcVar4 == '?') {
        iVar5 = format_buffer_acquire();
        format_buffer_free(iVar5);
        format_options_set(1);
        iVar5 = format_class_name(g_scope_vector->entries[(short)sym->scope_index]);
        pcVar6 = format_buffer_text(iVar5);
        uVar7 = 0xffffffff;
        pcVar4 = g_debug_symbol_name_buffer;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        strncpy((char *)(~uVar7 + 0x104dc413),pcVar6,0x101 - (~uVar7 - 1));
        g_debug_symbol_name_buffer[0x100] = '\0';
        format_options_clear(1);
        format_buffer_leave();
        return g_debug_symbol_name_buffer;
      }
      uVar7 = 0xffffffff;
      pcVar6 = g_debug_symbol_name_buffer;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
    }
    else {
      uVar7 = 0xffffffff;
      pcVar4 = g_debug_symbol_name_buffer;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar4 = sym->name->text;
    }
  }
  else {
    uVar7 = 0xffffffff;
    pcVar4 = g_debug_symbol_name_buffer;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    strncpy((char *)(~uVar7 + 0x104dc413),"operator",0x101 - (~uVar7 - 1));
    g_debug_symbol_name_buffer[0x100] = '\0';
    if ((sym->flags1 & 0x40) != 0) {
      iVar5 = format_buffer_acquire();
      format_buffer_free(iVar5);
      type = type_get_base(sym->type);
      iVar5 = format_symbol_declaration_text((c1_symbol *)0x0,type);
      pcVar6 = format_buffer_text(iVar5);
      uVar7 = 0xffffffff;
      pcVar4 = pcVar6;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      if (pcVar6[~uVar7 - 2] == ' ') {
        pcVar6[~uVar7 - 2] = '\0';
      }
      uVar7 = 0xffffffff;
      pcVar4 = g_debug_symbol_name_buffer;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      strncpy((char *)(~uVar7 + 0x104dc413)," ",0x101 - (~uVar7 - 1));
      uVar7 = 0xffffffff;
      g_debug_symbol_name_buffer[0x100] = '\0';
      pcVar4 = g_debug_symbol_name_buffer;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      strncpy((char *)(~uVar7 + 0x104dc413),pcVar6,0x101 - (~uVar7 - 1));
      g_debug_symbol_name_buffer[0x100] = '\0';
      format_buffer_leave();
      return g_debug_symbol_name_buffer;
    }
    cVar3 = (sym->tail).fn.op_token;
    if ((cVar3 == 0x8c) || (cVar3 == 0x8d)) {
      uVar7 = 0xffffffff;
      pcVar4 = g_debug_symbol_name_buffer;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      strncpy((char *)(~uVar7 + 0x104dc413)," ",0x101 - (~uVar7 - 1));
    }
    g_debug_symbol_name_buffer[0x100] = '\0';
    uVar7 = 0xffffffff;
    pcVar4 = g_debug_symbol_name_buffer;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = sym->name->text;
  }
  strncpy((char *)(~uVar7 + 0x104dc413),pcVar4,0x101 - (~uVar7 - 1));
  g_debug_symbol_name_buffer[0x100] = '\0';
  return g_debug_symbol_name_buffer;
}

