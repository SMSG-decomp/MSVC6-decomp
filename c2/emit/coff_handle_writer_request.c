void __fastcall coff_handle_writer_request(c2_comment_record *r)

{
  char cVar1;
  char *pb;
  uint uVar2;
  char *pcVar3;
  
  switch(r->kind) {
  case 1:
    pb = "Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 12.00.8168.0";
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x6a4);
  case 3:
    coff_write_directive_record(s___comment__107ac5f0,r->value,(char *)0x0,1);
    return;
  case 4:
    coff_write_directive_record(s__defaultlib__107ac5e0,r->value,(char *)0x0,0);
    return;
  case 6:
    pb = r->value;
    break;
  case 7:
    g_coff_debug_types_precomp = 1;
    return;
  case 9:
    coff_write_directive_record(s__nodefaultlib__107ac610,r->value,(char *)0x0,0);
    return;
  case 10:
    coff_write_directive_record("",r->value,(char *)0x0,0);
    return;
  }
  if (g_coff_trailer_data == (c2_coff_data *)0x0) {
    g_coff_trailer_data = coff_new_section_chunk(1,0);
  }
  uVar2 = 0xffffffff;
  pcVar3 = pb;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  g_coff_current_section_data = g_coff_trailer_data;
  coff_write_bytes(pb,~uVar2);
  return;
}

