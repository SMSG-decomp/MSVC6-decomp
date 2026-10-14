char * __fastcall decorate_c_name(c2_fe_symbol *s,char *name,int arena)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *decorated;
  char *pcVar5;
  
  uVar3 = 0xffffffff;
  pcVar2 = name;
  do {
    pcVar5 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  decorated = g_external_name_buffer + 1;
  g_external_name_buffer[0] = '_';
  g_external_name_buffer[1] = '\0';
  pcVar2 = pcVar5 + -uVar3;
  pcVar5 = g_external_name_buffer + 1;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  cVar1 = *name;
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  if ((cVar1 == '?') && (s->role == '\0')) goto switchD_10742779_caseD_3;
  switch(*(undefined1 *)((int)decorate_c_name_jump_table + s->cls + 0x13)) {
  case 0:
switchD_10742779_caseD_0:
    decorated = g_external_name_buffer;
    break;
  case 1:
    if (s->role != '\0') {
      return (char *)0x0;
    }
    decorated = g_external_name_buffer;
    g_external_name_buffer[0] = '$';
    break;
  case 2:
    switch(s->attrs & 0x1c) {
    default:
      goto switchD_10742779_caseD_0;
    case 4:
    case 0x14:
    case 0x18:
      decorated = g_external_name_buffer;
      g_external_name_buffer[0] = '@';
      break;
    case 8:
    case 0xc:
      break;
    }
  }
switchD_10742779_caseD_3:
  if (((s->cls == '\x01') || (s->cls == '\x04')) && ((s->storage & 0x1000) != 0)) {
    uVar3 = 0xffffffff;
    pcVar2 = decorated;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    memmove(decorated + 6,decorated,~uVar3);
    builtin_strncpy(decorated,"__imp_",6);
  }
  uVar3 = 0xffffffff;
  pcVar2 = decorated;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  g_fe_symbol_bytes[arena] = g_fe_symbol_bytes[arena] + (~uVar3 - 1);
  pcVar2 = arena_strdup(decorated,arena);
  return pcVar2;
}

