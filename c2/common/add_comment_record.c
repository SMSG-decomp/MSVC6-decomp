void __fastcall add_comment_record(int a,int b)

{
  c2_comment_record *pcVar1;
  c2_comment_record *pcVar2;
  
  pcVar1 = (c2_comment_record *)&g_coff_comment_records;
  for (pcVar2 = g_coff_comment_records; pcVar2 != (c2_comment_record *)0x0; pcVar2 = pcVar2->next) {
    pcVar1 = pcVar2;
  }
  pcVar2 = arena_alloc(1,0xc);
  pcVar2->kind = a;
  pcVar2->value = (char *)b;
  pcVar1->next = pcVar2;
  return;
}

