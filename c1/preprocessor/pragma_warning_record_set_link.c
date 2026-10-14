void __thiscall pragma_warning_record_set_link(uint *record,uint link,int is_mark)

{
  *record = link;
  if (is_mark == 0) {
    *record = link | 1;
  }
  return;
}

