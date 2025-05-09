# Motion-Detection & Parallel Image Processing

This project combines real-time motion detection with a future roadmap for a multithreaded parallel image processing system.

## Features

- **Real-Time Motion Detection**
  - RTSP stream support (or file input)
  - Frame-differencing based motion detection
  - HTTP notification on motion events via Boost.Asio
- **Parallel Image Processing (Future)**
  - Pipeline stages to be parallelized using [taskflow](https://github.com/taskflow/taskflow)
  - Scalable task graph for filter application, feature extraction, and analysis
  - Thread-safe buffering and image queue management

## Libraries

- **OpenCV**: Image processing and computer vision
- **Boost.Asio**: Asynchronous networking for notifications
- **taskflow**: Parallel task management (planned)

## Installation & Build

```bash
git clone https://github.com/your-repo/motion_detection.git
cd motion_detection
mkdir build && cd build
cmake ..
make
```

## Configuration

Create a `.env` file in the project root:

```dotenv
CAMERA_URL=rtsp://<username>:<password>@<ip_address>/stream
MOTION_THRESHOLD=5000.0
NOTIFY_HOST=example.com
NOTIFY_PATH=/notify
NOTIFY_PORT=80
```

## Usage

```bash
# Load environment variables
export $(grep -v '^#' .env | xargs)
# Run the application
./motion_detection
```

## TODO

- [ ] Integrate taskflow for parallelizing image processing stages
- [ ] Implement thread-safe frame buffers for producer-consumer model
- [ ] Add dynamic configuration (watch and reload `.env` at runtime)
- [ ] Develop plugin system for custom image filters
- [ ] Write comprehensive unit and integration tests
- [ ] Provide Dockerfile for containerized deployment

## Dependencies

- OpenCV
- Boost.Asio
- taskflow (upcoming)
- CMake

## License

MIT
