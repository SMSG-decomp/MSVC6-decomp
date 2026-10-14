void __cdecl browse_record_write(c1_browse_record *rec)

{
  c1_u8 cVar1;
  ushort uVar2;
  byte bVar3;
  c1_u8 *pcVar4;
  int iVar5;
  char cVar7;
  uint uVar6;
  char *pcVar8;
  char *pcVar9;
  FILE *pFVar10;
  char cStack_106;
  uint local_104;
  char text [256];
  
  if (0xffff < (rec->id & 0xffffff) + 0x8000) {
    rec->kind = rec->kind | 0x40;
  }
  cVar1 = rec->kind;
  g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
  if (g_browse_out_file->_cnt < 0) {
    _flsbuf((int)(char)cVar1,g_browse_out_file);
  }
  else {
    *g_browse_out_file->_ptr = cVar1;
    g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
  }
  bVar3 = rec->kind & 0xbf;
  if ((0x1f < bVar3) && (bVar3 < 0x30)) {
    browse_record_write_fragment();
    return;
  }
  switch(rec->kind & 0xbf) {
  case 0:
  case 0x16:
    g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
    if (g_browse_out_file->_cnt < 0) {
      _flsbuf(2,g_browse_out_file);
    }
    else {
      *g_browse_out_file->_ptr = '\x02';
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
    }
    g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
    if (g_browse_out_file->_cnt < 0) {
      _flsbuf(0,g_browse_out_file);
    }
    else {
      *g_browse_out_file->_ptr = '\0';
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
    }
    g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
    if (g_browse_out_file->_cnt < 0) {
      _flsbuf(2,g_browse_out_file);
    }
    else {
      *g_browse_out_file->_ptr = '\x02';
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
    }
    g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
    if (-1 < g_browse_out_file->_cnt) {
      *g_browse_out_file->_ptr = '\0';
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
      pFVar10 = g_browse_out_file;
      pcVar4 = cwd_string();
      file_put_string_with_nul((char *)pcVar4,pFVar10);
      return;
    }
    _flsbuf(0,g_browse_out_file);
    pFVar10 = g_browse_out_file;
    pcVar4 = cwd_string();
    file_put_string_with_nul((char *)pcVar4,pFVar10);
    return;
  case 1:
  case 0xf:
    file_put_string_with_nul(rec->name,g_browse_out_file);
    return;
  case 2:
  case 0x15:
    uVar2 = (ushort)rec->line;
    local_104 = (uint)uVar2;
    iVar5 = g_browse_out_file->_cnt + -2;
    g_browse_out_file->_cnt = iVar5;
    if (-1 < iVar5) {
      *(ushort *)g_browse_out_file->_ptr = uVar2;
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 2;
      return;
    }
    g_browse_out_file->_cnt = g_browse_out_file->_cnt + 2;
    fwrite(&local_104,2,1,g_browse_out_file);
    return;
  case 3:
    cVar1 = rec->sub_kind;
    g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
    if (g_browse_out_file->_cnt < 0) {
      _flsbuf((int)(char)cVar1,g_browse_out_file);
    }
    else {
      *g_browse_out_file->_ptr = cVar1;
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
    }
    iVar5 = g_browse_out_file->_cnt + -2;
    g_browse_out_file->_cnt = iVar5;
    if (iVar5 < 0) {
      g_browse_out_file->_cnt = g_browse_out_file->_cnt + 2;
      fwrite(&rec->attributes,2,1,g_browse_out_file);
    }
    else {
      *(c1_u16 *)g_browse_out_file->_ptr = rec->attributes;
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 2;
    }
    uVar6 = rec->id & 0xffffff;
    g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
    if (g_browse_out_file->_cnt < 0) {
      _flsbuf((int)(char)uVar6,g_browse_out_file);
    }
    else {
      *g_browse_out_file->_ptr = (char)uVar6;
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
    }
    g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
    cVar7 = (char)(uVar6 >> 8);
    if (g_browse_out_file->_cnt < 0) {
      _flsbuf((int)cVar7,g_browse_out_file);
    }
    else {
      *g_browse_out_file->_ptr = cVar7;
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
    }
    if ((rec->kind & 0x40) != 0) {
      g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
      cStack_106 = (char)(uVar6 >> 0x10);
      if (g_browse_out_file->_cnt < 0) {
        _flsbuf((int)cStack_106,g_browse_out_file);
      }
      else {
        *g_browse_out_file->_ptr = cStack_106;
        g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
      }
    }
    pcVar8 = rec->name;
    if (pcVar8 == (char *)0x0) {
      file_put_string_with_nul("",g_browse_out_file);
      browse_record_write_fragment();
      return;
    }
    uVar6 = 0xffffffff;
    pcVar9 = pcVar8;
    break;
  case 4:
  case 5:
  case 0xb:
    uVar6 = rec->id & 0xffffff;
    g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
    if (g_browse_out_file->_cnt < 0) {
      _flsbuf((int)(char)uVar6,g_browse_out_file);
    }
    else {
      *g_browse_out_file->_ptr = (char)uVar6;
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
    }
    g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
    cVar7 = (char)(uVar6 >> 8);
    if (g_browse_out_file->_cnt < 0) {
      _flsbuf((int)cVar7,g_browse_out_file);
    }
    else {
      *g_browse_out_file->_ptr = cVar7;
      g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
    }
    if ((rec->kind & 0x40) != 0) {
      g_browse_out_file->_cnt = g_browse_out_file->_cnt + -1;
      cStack_106 = (char)(uVar6 >> 0x10);
      if (-1 < g_browse_out_file->_cnt) {
        *g_browse_out_file->_ptr = cStack_106;
        g_browse_out_file->_ptr = g_browse_out_file->_ptr + 1;
        return;
      }
      _flsbuf((int)cStack_106,g_browse_out_file);
      return;
    }
  default:
    return;
  }
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar7 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar7 != '\0');
  if (~uVar6 - 1 < 0x100) {
    file_put_string_with_nul(pcVar8,g_browse_out_file);
    return;
  }
  diag_warning(3,0x312,pcVar8,0xff,0x165);
  pcVar8 = rec->name;
  pcVar9 = text;
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar9 = pcVar9 + 4;
  }
  *(undefined2 *)pcVar9 = *(undefined2 *)pcVar8;
  pcVar9[2] = pcVar8[2];
  text[0xff] = '\0';
  file_put_string_with_nul(text,g_browse_out_file);
  return;
}

