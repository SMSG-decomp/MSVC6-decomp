uint8_t * __fastcall fe_symbol_external_name(c2_fe_symbol *s)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  pcVar6 = s->name;
  if (pcVar6 != (char *)0x0) {
    uVar2 = 0xffffffff;
    pcVar5 = pcVar6;
    do {
      pcVar7 = pcVar5;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar7 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar7;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar5 = pcVar7 + -uVar2;
    pcVar7 = g_external_name_buffer;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    g_external_name_buffer[g_opt_max_identifier] = '\0';
    if (g_external_name_buffer[0] == '?') goto switchD_10741663_caseD_9;
  }
  switch(s->cls) {
  case '\x01':
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x4ed);
  case '\x03':
    if (s->role == '\0') {
      uVar2 = 0xffffffff;
      pcVar6 = "$";
      do {
        pcVar5 = pcVar6;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar5 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar5;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      iVar4 = -1;
      pcVar6 = g_external_name_buffer;
      do {
        pcVar7 = pcVar6;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      pcVar6 = pcVar5 + -uVar2;
      pcVar5 = pcVar7 + -1;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar5 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar5 = pcVar5 + 1;
      }
    }
    else {
      if (pcVar6 != (char *)0x0) goto switchD_10741663_caseD_9;
      g_external_name_buffer[0] = '$';
      g_external_name_buffer[1] = 'L';
      g_external_name_buffer[2] = '\0';
    }
LAB_10741713:
    uVar2 = 0xffffffff;
    pcVar6 = g_external_name_buffer;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (((g_pdb_il_mode != 0) && (uVar3 = s->id, 0x3effff < uVar3)) && (uVar3 < 0x400000)) {
      format_local_label_name(uVar3,(char *)((int)&g_pch_name + ~uVar2 + 3));
      return (uint8_t *)g_external_name_buffer;
    }
    format_integer(s->id,(char *)((int)&g_pch_name + ~uVar2 + 3),10);
    return (uint8_t *)g_external_name_buffer;
  case '\x04':
    if (pcVar6 == (char *)0x0) {
      g_external_name_buffer[0] = '$';
      g_external_name_buffer[1] = 'E';
      if (((g_pdb_il_mode == 0) || (uVar2 = s->id, uVar2 < 0x3f0000)) || (0x3fffff < uVar2)) {
        format_integer(s->id,g_external_name_buffer + 2,10);
        return (uint8_t *)g_external_name_buffer;
      }
      format_local_label_name(uVar2,g_external_name_buffer + 2);
    }
  case '\t':
switchD_10741663_caseD_9:
    return (uint8_t *)g_external_name_buffer;
  }
  if (pcVar6 != (char *)0x0) {
    if ((s->cls == '\x01') && ((uVar2 = s->storage & 0x70, uVar2 == 0x10 || (uVar2 == 0x30)))) {
      uVar2 = 0xffffffff;
      pcVar6 = "$";
      do {
        pcVar5 = pcVar6;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar5 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar5;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      iVar4 = -1;
      pcVar6 = g_external_name_buffer;
      do {
        pcVar7 = pcVar6;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      pcVar6 = pcVar5 + -uVar2;
      pcVar5 = pcVar7 + -1;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar5 = pcVar5 + 4;
      }
      cVar1 = *(char *)((int)&s->refcount + 2);
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar5 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar5 = pcVar5 + 1;
      }
      if (cVar1 < '\x03') {
        return (uint8_t *)g_external_name_buffer;
      }
      goto LAB_10741713;
    }
    goto switchD_10741663_caseD_9;
  }
  if (s->role == '$') {
    g_external_name_buffer[0] = '$';
    g_external_name_buffer[1] = 'S';
  }
  else {
    if (s->role == '%') {
      g_external_name_buffer[0] = '$';
      g_external_name_buffer[1] = 'S';
      g_external_name_buffer[2] = 'G';
      iVar4 = 3;
      goto LAB_107416c5;
    }
    g_external_name_buffer[0] = '$';
    g_external_name_buffer[1] = 'T';
  }
  iVar4 = 2;
LAB_107416c5:
  if (((g_pdb_il_mode != 0) && (uVar2 = s->id, 0x3effff < uVar2)) && (uVar2 < 0x400000)) {
    format_local_label_name(uVar2,g_external_name_buffer + iVar4);
    return (uint8_t *)g_external_name_buffer;
  }
  format_integer(s->id,g_external_name_buffer + iVar4,10);
  return (uint8_t *)g_external_name_buffer;
}

