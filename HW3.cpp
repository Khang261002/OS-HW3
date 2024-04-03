// Khang Duong
// B323A775

#include <iostream>
#include <unordered_map>
#include <iomanip>

class PageToFrame {
private:
    std::unordered_map<int, int> table; // Page table to map logical page numbers to physical frame numbers

public:
    PageToFrame() {}

    // Method to map a page to a frame
    void mapping(int page_number, int frame_number) {
        table[page_number] = frame_number;
    }

    // Method to get the frame number for a given page number
    int getFrameNumber(int page_number) {
        return table[page_number];
    }
};

// Translate logical addresses to physical addresses using the page/frame table
void translateLogicalAddress(int logical_address, PageToFrame& page_frame_table) {
    int page_number = (logical_address >> 8) & 0xFF;
    int offset = logical_address & 0xFF;
    int frame_number = page_frame_table.getFrameNumber(page_number);

    if (frame_number == 0) {
        std::cout << "Page fault occurred for logical address: " 
                  << std::uppercase << std::hex << std::setw(4) << std::setfill('0') 
                  << logical_address << std::endl;
        return;
    }

    int physical_address = (frame_number << 8) | offset;

    std::cout << "Logical Address: " << std::uppercase << std::hex << std::setw(4) << std::setfill('0') << logical_address
              << " => Page Number: " << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << page_number
              << ", Offset: " << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << offset
              << ", Physical Address: " << std::uppercase << std::hex << std::setw(4) << std::setfill('0') << physical_address << std::endl;
}

int main() {
    PageToFrame page_frame_table;

    page_frame_table.mapping(0x3A, 0x0D);
    page_frame_table.mapping(0xAB, 0x2B);
    page_frame_table.mapping(0x56, 0x15);

    int logical_addresses[] = {0x3A7F, 0xABCD, 0x5678};

    for (int address : logical_addresses) {
        translateLogicalAddress(address, page_frame_table);
    }

    return 0;
}
