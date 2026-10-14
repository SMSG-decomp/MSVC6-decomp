void __cdecl print_diagnostic(int number_base,int id,char *fmt,char *args)

{
  char cVar1;
  uint32_t uVar2;
  char *pcVar3;
  uint uVar4;
  int id_00;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *file_name;
  char local_920 [2336];
  
  pcVar6 = local_920;
  if (g_diag_line_needs_mapping == 0) {
    file_name = g_cur_source_file;
    uVar2 = g_current_line_abs;
  }
  else {
    uVar2 = g_current_line_abs;
    if (g_current_line_abs == 0) {
      uVar2 = g_cur_function_line_base + 1;
    }
    uVar2 = line_to_file_line(uVar2,&file_name);
  }
  if ((file_name != (char *)0x0) && (*file_name != '\0')) {
    format_message_va(local_920,"%s(%ld) : ",file_name,uVar2);
    uVar4 = 0xffffffff;
    pcVar6 = local_920;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    pcVar6 = local_920 + (~uVar4 - 1);
  }
  if (number_base != 0) {
    if (number_base == 1000) {
      id_00 = 0x12f;
    }
    else if (number_base == 2000) {
      id_00 = 0x12e;
    }
    else {
      id_00 = 0x12d;
    }
    pcVar3 = load_message(id_00);
    uVar4 = 0xffffffff;
    pcVar7 = pcVar3;
    do {
      pcVar8 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar7 = pcVar8 + -uVar4;
    pcVar8 = pcVar6;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    uVar4 = 0xffffffff;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar6 = pcVar6 + (~uVar4 - 1);
    format_message_va(pcVar6," %c%d: ",(-(uint)(g_opt_fortran_frontend != 0) & 3) + 0x43,
                      number_base + id);
    uVar4 = 0xffffffff;
    pcVar3 = pcVar6;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar6 = pcVar6 + (~uVar4 - 1);
  }
  format_message_args(pcVar6,fmt,args);
  uVar4 = 0xffffffff;
  pcVar6 = local_920;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  fwrite(local_920,~uVar4 - 1,1,(FILE *)(_iob_exref + 0x40));
  fwrite("\n",1,1,(FILE *)(_iob_exref + 0x40));
  return;
}

