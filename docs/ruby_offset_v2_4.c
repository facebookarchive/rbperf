// clang -I ~/Projects/ruby -I ~/Projects/ruby/include -I ~/.asdf/installs/ruby/2.4.10/include/ruby-2.4.0/x86_64-linux ./ruby_offset.c

#include <stdio.h>
#include <stddef.h>

#include "vm_core.h"
#include "iseq.h"

int main() {
  printf("offsets_for_version[(\"x.y.z\",)] = VersionConfig(\n");
  printf("    vm_offset=c_int(0x%lx),  # offsetof(struct rb_thread_struct, stack)\n", offsetof(struct rb_thread_struct, stack));
  printf("    vm_size_offset=c_int(0x%lx),  # offsetof(struct rb_thread_struct, stack_size)\n", offsetof(struct rb_thread_struct, stack_size));
  printf("    control_frame_t_sizeof=c_int(0x%lx),  # sizeof(rb_control_frame_t)\n", sizeof(rb_control_frame_t));
  // for old versions at least <2.5
  printf("    cfp_offset=c_int(0x%lx),  # offsetof(struct rb_thread_struct, cfp)\n", offsetof(struct rb_thread_struct, cfp));
  // for modern versions
  // printf("    cfp_offset=c_int(0x%lx),  # offsetof(struct rb_execution_context_struct, cfp)\n", offsetof(struct rb_execution_context_struct, cfp));
  printf("    label_offset=c_int(0x%lx),  # offsetof(struct rb_iseq_location_struct, label)\n", offsetof(struct rb_iseq_location_struct, label));
  printf("    path_flavour=c_int(?),\n");
  printf("    line_info_size_offset=c_int(0x%lx),  # offsetof(struct rb_iseq_constant_body, line_info_size)\n", offsetof(struct rb_iseq_constant_body, line_info_size));
  printf("    line_info_table_offset=c_int(0x%lx),  # offsetof(struct rb_iseq_constant_body, line_info_table)\n", offsetof(struct rb_iseq_constant_body, line_info_table));
  printf("    lineno_offset=c_int(0x%lx),  # offsetof(struct iseq_line_info_entry, line_no)\n", offsetof(struct iseq_line_info_entry, line_no));
  printf(")\n");

  return 0;
}
