void __thiscall vector_push_triple(int *v,int a,int b,int c)

{
  c1_line_map_row *pcVar1;
  
  pcVar1 = vector_push_12((c1_line_map *)v);
  pcVar1->position = a;
  pcVar1->line = b;
  pcVar1->file = (fe_file_record *)c;
  return;
}

